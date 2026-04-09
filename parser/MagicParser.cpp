#include "MagicParser.h"
#include <iostream>
#include <fstream>

std::optional<MagicPacket> MagicParser::parse(const std::string& filepath) const
{
    std::ifstream file(filepath, std::ios::binary);

    if (!file) return std::nullopt;

    uint32_t signature = 0;
    uint32_t packetCount = 0;

    file.read(reinterpret_cast<char*>(&signature), sizeof(signature));
    file.read(reinterpret_cast<char*>(&packetCount), sizeof(packetCount));

    if (!file) return std::nullopt;

    if (signature != 0xDEADBEEF) {
        std::cout << "incorrect signature\n";
        return std::nullopt; //наследуемый I через optional позволяет вернуть: либо один пакет либо nullopt
    }

    if (( packetCount == 0) || (packetCount > 100)) {
        std::cout << "incorrect packet count\n";
        return std::nullopt;
    }

    std::vector<MagicPacket> packets;
    //читаем пакеты
    for (uint32_t i = 0; i < packetCount; i++)
    {
        MagicPacket packet;
        file.read(reinterpret_cast<char*>(&packet.num),sizeof(packet.num));
        file.read(reinterpret_cast<char*>(&packet.type),sizeof(packet.type));

        if (!file) return std::nullopt;

        uint32_t dataCount = 0;
        file.read(reinterpret_cast<char*>(&dataCount), sizeof(dataCount));
        if (dataCount > 100) return std::nullopt;

        if (!file) return std::nullopt;

        for (uint32_t j = 0; j < dataCount; j++)
        {
            MagicData d;

            file.read(reinterpret_cast<char*>(&d.id), sizeof(d.id));
            file.read(reinterpret_cast<char*>(&d.param), sizeof(d.param));
            file.read(reinterpret_cast<char*>(&d.value), sizeof(d.value));

            if (!file) return std::nullopt;

            packet.data.push_back(d);
        }
        packets.push_back(packet);
    }

    if (file.peek() != EOF) //End Of File встроенное значение
    return std::nullopt;

    if (packets.empty())
    return std::nullopt;

    //т.к I должен вернуть один пакет
    return packets.back();
}