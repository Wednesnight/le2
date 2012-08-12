#ifndef LOST_PREFIX_SHARED_H
#define LOST_PREFIX_SHARED_H

#ifdef __cplusplus

#include <stdint.h>
#include "lost/types.h"

#ifndef LOST_USE_EASTL
  #include <string>
  #include <list>
  #include <map>
  #include <vector>
  namespace lost
  {
    using std::string;
    using std::basic_string;
    using std::list;
    using std::map;
    using std::vector;
    using std::make_pair;
    using std::pair;
  }
#else
#endif

#include "lost/StringStream.h"

#define THROW_RTE(s) \
{ \
lost::StringStream os; \
os << s; \
throw std::runtime_error(os.str().c_str()); \
}

#include "lost/shared_ptr.h"
#include "lost/Platform.h"

#endif

#endif
