#include "File.hh"

File::File(std::string nm, double sz):Node(nm){_size=sz;}
double File::getSize(){return _size;}