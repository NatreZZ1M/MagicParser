#include <iostream>
#include "parser/MagicParser.h"

int main() {
    MagicParser parser;

    auto result = parser.parse("test/valid.bin");

    if (!result) {
        std::cout << "parser error\n";
        std::cin.get();
        return 1;
    }

    const MagicPacket& packet = *result;

    std::cout << "Packet:\n";
    std::cout << "  num: " << (int)packet.num << "\n"; //т.к это char явно указываем тип, чтобы не интерпритировал как символ
    std::cout << "  type: " << (int)packet.type << "\n";
    std::cout << "  data:\n";

    for (const auto& d : packet.data) {
        std::cout << "    id=" << d.id
                  << " param=" << (int)d.param
                  << " value=" << d.value << "\n";
    }

    std::cin.get();
    return 0;
}