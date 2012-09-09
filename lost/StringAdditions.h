#ifndef LOST_STRINGADDITIONS_H
#define LOST_STRINGADDITIONS_H

namespace lost
{

bool replace(string& value,
             string const& search,
             string const& replace);


string trim(const string& pString,
            const string& pWhitespace = " \t");

void split(const string& str,
           vector<string>& tokens,
           const string& delimiters = " ",
           const bool trimEmpty = false);

//  "\r\n" and "\r" to "\n"
void normaliseLinebreaks(string& data);

}


#endif

