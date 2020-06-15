//---------------------------------------------------------------------------

#pragma hdrstop

#include "Container.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
bool TRegionBook::Contain(TRegion region){
	//ShowMessage(region.region+"\n"+region.center);
	if (!this->book.size()) return false;
	for (list <TRegion>::iterator i = this->book.begin(); i != this->book.end(); ++i)
		if(*i==region) return true;
	return false;
}
