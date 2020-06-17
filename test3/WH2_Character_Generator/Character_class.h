#pragma once
#include <string>
#include <vector>

//				0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19
//				WW	US	K	ODP	ZR	INT	SW	OGD	A	ŻYW	SW	OGD	A	ŻYW	S	WT	SZ	MAG	PO	PP

class Character_profession
{
public: //std::string stats_profession[16] = {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "};
		std::vector <std::string> equipment;
};

		//////////////////////// DZIEDZICZENIE ///////////////////////////
class Fighter : public Character_profession
{
public: Fighter();
};


class Hunter : public Character_profession
{
public: Hunter();
};

void profession_roll();
