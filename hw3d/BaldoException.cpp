#include "BaldoException.h"
#include <sstream>

BaldoException::BaldoException(int line, const char* file) noexcept
	: line(line), file(file)
{
}

const char* BaldoException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* BaldoException::GetType() const noexcept
{
	return "Baldo Exception";
}

int BaldoException::GetLine() const noexcept
{
	return line;
}

const std::string& BaldoException::GetFile() const noexcept
{
	return file;
}

std::string BaldoException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}
