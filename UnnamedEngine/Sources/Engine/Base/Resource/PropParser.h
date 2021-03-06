#pragma once
#include "Engine/Base/Common/Common.h"

#include <string>
#include <optional>

struct PropTree;
struct UDFToken;
class PropTreeLeafBase;

class PropParser
{
public:
	PropParser();
	static PropTree Parse(std::string str);

	static void Tokenize(std::string str, std::vector<UDFToken>& tokens);
	static void ParserFailed(int lineNumber, std::string around);
	static bool ParseValueTokens(PropTree& tree, const std::string& identifier, const std::vector<UDFToken>& valueTokens);
	static PropTree ParseTokens(std::vector<UDFToken>& tokens);
};

