#include "CFileData.h"

CFileData::CFileData(std::string fileName, FILETYPES type, unsigned char *data, __int64 fileSize, __int64 filePos)
{
	_fileName = fileName;
	_type = type;
	_data = data;
	_fileSize = fileSize;
	_filePos = filePos;
}

CFileData::~CFileData()
{
	delete [] _data;
}

double CFileData::toDouble(__int64 start)
{
  double * result = 0;
  unsigned char bits[4];

  for (__int64 i = start; i < 4; i++)
		bits[i] = _data[i];

  result = (double*)bits;

  return *result;
}

unsigned short int CFileData::toUShort(__int64 start)
{
	unsigned short int result = 0;
	unsigned char * bits = new unsigned char[2];

	for (__int64 i = start; i < 2; i++)
		bits[i] = _data[i];

	for (int n = sizeof( result ); n >= 0; n--)
		result = (result << 8) +bits[ n ];

	delete bits;
	bits = 0;
	return result;
}

__int32 CFileData::toInt(__int64 start)
{
  __int32 result = 0;
  unsigned char * bits = new unsigned char[4];

  for (__int64 i = start; i < 4; i++)
		bits[i] = _data[i];

  for (int n = sizeof( result ); n >= 0; n--)
    result = (result << 8) +bits[ n ];

  delete bits;
  bits = 0;

  return result;
}

__int64 CFileData::toLong(__int64 start)
{
  __int64 result = 0;
  unsigned char * bits = new unsigned char[4];

  for (__int64 i = start; i < 4; i++)
		bits[i] = _data[i];

  for (int n = sizeof( result ); n >= 0; n--)
    result = (result << 8) +bits[ n ];

  delete bits;
  bits = 0;

  return result;
}

std::string CFileData::getName()
{
	return _fileName;
}

unsigned char * CFileData::getData()
{
	return _data;
}

std::string CFileData::getDataRange(__int64 startPos, __int64 length)
{
	std::string temp = "";
	std::stringstream stream(std::stringstream::in);

	for (__int64 i = startPos; i < startPos + length; i++)
		stream << _data[i];

	stream >> temp;

	return temp;
}

__int64 CFileData::getSize()
{
	return _fileSize;
}

__int64 CFileData::getPos()
{
	return _filePos;
}
FILETYPES CFileData::getType()
{
	return _type;
}