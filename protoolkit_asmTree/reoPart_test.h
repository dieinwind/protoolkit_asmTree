#pragma once
#include "creoFeature.h"
class reoPart_test :
	public creoFeature
{
private:

	ProFeattype FeatureType;  // PRO_FEAT_COMPONENT
	ProName Mdlname; // <PRT0001> //����
	ProPath Origin; // <F:\Project\data_exchange\creo_workspace\protoolkit_asmTree\asm\prt0001.prt.1> //����·��
	ProMdlExtension Extension; // <PRT>  //��չ��
	ProPath DirectoryPath; // <F:\Project\data_exchange\creo_workspace\protoolkit_asmTree\asm\>
	ProMdlType MdlType; // <2> PRO_PART
	ProMdlFileName Displayname; // <PRT0001.PRT> //����

public:
	reoPart_test();
	~reoPart_test();
};

