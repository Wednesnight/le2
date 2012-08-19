#include "lost/Bundle.h"
#include "lost/PlatformPaths.h"
#include "lost/Log.h"
#include <stdio.h>

namespace lost
{

Bundle::Bundle()
{
  
}

Bundle::Bundle(const Path& inPath)
: _path(inPath)
{

}

DataPtr Bundle::load(const Path& relativePath) const
{
  DataPtr result(new Data);
  
  Path absolutePath = _path / relativePath;
  string spath = absolutePath.string();
  DOUT("LOADING: '"<<spath<<"'");
  FILE* file;
  ASSERT(file = fopen(spath.c_str(), "rb"), "couldn't open file");
  ASSERT(0 == fseek(file, 0, SEEK_END), "couldn't seek");
  fpos_t size;
  ASSERT(0 == fgetpos(file, &size), "couldn't get file pos");
  result->bytes.reset(new char[size]);
  ASSERT(0 == fseek(file, 0, SEEK_SET), "couldn't seek");
  ASSERT(0 == fread(result->bytes.get(), size, 1, file), "couldn't read");
  ASSERT(0 == fclose(file), "couldn't close"); 
  return result;
}

ResourceBundle::ResourceBundle()
: Bundle(getResourcePath())
{
}

}