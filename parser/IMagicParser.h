#pragma once
#include "MagicPacket.h"

#include <optional>  
#include <string>  

class IMagicParser {  
    public:  
    virtual ~IMagicParser() = default;  
    virtual std::optional<MagicPacket> parse(const std::string& filepath) const = 0;  
};