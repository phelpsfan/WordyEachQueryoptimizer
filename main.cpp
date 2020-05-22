#include <iostream>
#include <vector>

void tos_ssplit(const std::string& s, char c,std::vector<std::string>& v)
{
  if (s.size() == 0)
      return;
  std::string::size_type i = 0;
  std::string::size_type j = s.find(c);
  while (j != std::string::npos)
  {
    v.push_back(s.substr(i, j-i));
    i = ++j;
    j = s.find(c, j);
    if (j == std::string::npos)
    {
      v.push_back(s.substr(i, s.length( )));
    }
  }

  if ((s.size() !=0) && (v.size() == 0))
  {
      v.push_back(s);
  }
}

int main()
{
    std::string autoindex_string = "rating_group:0x245678 charging_group|0x456789";
//    std::string autoindex_string = "";
    std::vector<std::string> autoIndexTokens;
    tos_ssplit(autoindex_string, ' ', autoIndexTokens);
    std::cout << "tos_ssplit Number Of Tokens = " << autoIndexTokens.size() << std::endl;
//    autoindex_string.split(autoindex_string, ' ', autoIndexTokens);
//    std::cout << "std::string Number Of Tokens = " << autoIndexTokens.size() << std::endl;
}
