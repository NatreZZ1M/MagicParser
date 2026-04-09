#pragma once
#include <cstdint>  
#include <vector>  
#include "MagicData.h"

struct MagicPacket {  
uint8_t num; // номер пакета (1 байт)  
uint8_t type; // тип пакета (1 байт)  
std::vector<MagicData> data; // массив магических данных  
}; 