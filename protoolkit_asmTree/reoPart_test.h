#pragma once
#include "creoFeature.h"
class reoPart_test :
	public creoFeature
{
private:

	ProFeattype FeatureType;  // PRO_FEAT_COMPONENT
	ProName Mdlname; // <PRT0001> //名字
	ProPath Origin; // <F:\Project\data_exchange\creo_workspace\protoolkit_asmTree\asm\prt0001.prt.1> //完整路径
	ProMdlExtension Extension; // <PRT>  //拓展名
	ProPath DirectoryPath; // <F:\Project\data_exchange\creo_workspace\protoolkit_asmTree\asm\>
	ProMdlType MdlType; // <2> PRO_PART
	ProMdlFileName Displayname; // <PRT0001.PRT> //名字

public:
	reoPart_test();
	~reoPart_test();
};

