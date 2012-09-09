#include "lost/StringAdditions.h"

namespace lost
{

bool replace(string& value,
             string const& search,
             string const& replace)
{
  bool replaced = false;
  std::string::size_type  next;

  for(next = value.find(search);        // Try and find the first match
      next != std::string::npos;        // next is npos if nothing was found
      next = value.find(search,next)    // search for the next match starting after
                                        // the last match that was found.
     )
  {
    // Inside the loop. So we found a match.
    value.replace(next,search.length(),replace);   // Do the replacement.
    next += replace.length();                      // Move to just after the replace
                                                   // This is the point were we start
                                                   // the next search from.
    replaced = true;
  }
  return replaced;
}


string trim(const string& pString,
            const string& pWhitespace)
{
  const size_t beginStr = pString.find_first_not_of(pWhitespace);
  if (beginStr == std::string::npos)
  {
    // no content
    return "";
  }

  const size_t endStr = pString.find_last_not_of(pWhitespace);
  const size_t range = endStr - beginStr + 1;

  return pString.substr(beginStr, range);
}

void split(const std::string& str,
           vector<string>& tokens,
           const std::string& delimiters,
           const bool trimEmpty)
{
   std::string::size_type pos, lastPos = 0;
   while(true)
   {
      pos = str.find_first_of(delimiters, lastPos);
      if(pos == std::string::npos)
      {
         pos = str.length();

         if(pos != lastPos || !trimEmpty)
            tokens.push_back(string(str.data()+lastPos, pos-lastPos ));

         break;
      }
      else
      {
         if(pos != lastPos || !trimEmpty)
            tokens.push_back(string(str.data()+lastPos, pos-lastPos ));
      }

      lastPos = pos + 1;
   }
};

void normaliseLinebreaks(string& data)
{
  replace(data, "\r\n", "\n");
  replace(data, "\r", "\n");
}

}

