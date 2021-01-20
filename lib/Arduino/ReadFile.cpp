#include "ReadFile.h"

ReadFile::ReadFile(std::ifstream& data, const String& filename)
	: t_data(data), t_name(filename) {
	t_data.seekg(0, std::ios::end);
	t_size = t_data.tellg();
	t_data.seekg(0, std::ios::beg);
}

void ReadFile::seek(unsigned long pos)
{
	t_data.clear();
	t_data.seekg(pos);

}

unsigned long ReadFile::tell()
{
	return static_cast<unsigned long>(t_data.tellg());
}

const String& ReadFile::get_name() const
{
	return t_name;
}

char ReadFile::read()
{
	char result;
	t_data.read(&result, 1);
	return result;
}
