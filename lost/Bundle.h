#ifndef LOST_BUNDLE_H
#define LOST_BUNDLE_H

#include "lost/Path.h"
#include "lost/Data.h"

namespace lost
{

struct Bundle
{
  Bundle();
  Bundle(const Path& inPath);
  virtual ~Bundle() {};
  
  DataPtr load(const Path& relativePath) const;
  
  Path _path;
};


struct ResourceBundle : Bundle
{
  ResourceBundle();
};

}

#endif

