#pragma once
#include "IMagicParser.h"

class MagicParser : public IMagicParser {
    public :
    std::optional<MagicPacket> parse (const std::string& filepath) const override;
};