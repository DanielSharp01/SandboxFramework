#include "StringFuncs.h"

namespace Sandbox::StringFuncs
{
	bool EndsWith(const std::string& a, const std::string& b) {
		if (b.size() > a.size()) return false;
		return std::equal(a.begin() + a.size() - b.size(), a.end(), b.begin());
	}
}