#pragma once //игнорирует повторное подключение
#include <cstdint>  
#include <vector>  

struct MagicData {  
uint16_t id; // идентификатор заклинания (2 байта)  
uint8_t param; // параметр заклинания (1 байт) 
uint16_t value; // сила заклинания (2 байта)  
};  
