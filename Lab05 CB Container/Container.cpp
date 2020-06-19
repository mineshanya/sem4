//---------------------------------------------------------------------------

#pragma hdrstop

#include "Container.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
bool TRegionBook::Contain(TRegion region){
	if (!this->book.size()) return false;
	for (list <TRegion>::iterator i = this->book.begin(); i != this->book.end(); ++i)
		if(*i==region) return true;
	return false;
}
