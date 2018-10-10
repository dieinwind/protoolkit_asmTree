#pragma once
#include <Windows.h>
#include <io.h>
#include <time.h> 
#include <iostream>
#include <vector>
#include <direct.h>
#include <stdio.h>
#include <stdlib.h>
#include <ProToolkit.h>
#include <ProCore.h>
#include <ProUtil.h>
#include <ProPDF.h>
#include <ProWindows.h>
#include <ProMdl.h>
#include <ProSolid.h>
#include <ProFeature.h>
#include <ProFeatType.h>
#include <ProArray.h>
#include <ProDimension.h>
#include <ProParameter.h>
#include <ProParamval.h>
#include <ProModelitem.h>
#include <locale>

#include "creoFeature.h"
#include "creoPart.h"


#define FEATURE 2
#define PART 3
#define SUBASM 4
#define TOPASM 5

class creoAssembly
{
private:
	ProMdl assembly;
	ProFeature *Feature;
	ProMdl owner;

	ProFeattype FeatureType;  // PRO_FEAT_COMPONENT
	ProName Mdlname; // <PRT0001> //����
	ProPath Origin; // <F:\Project\data_exchange\creo_workspace\protoolkit_asmTree\asm\prt0001.prt.1> //����·��
	ProMdlExtension Extension; // <PRT>  //��չ��
	ProPath DirectoryPath; // <F:\Project\data_exchange\creo_workspace\protoolkit_asmTree\asm\>
	ProMdlType MdlType; // <2> PRO_PART
	ProMdlFileName Displayname; // <PRT0001.PRT> //����
	int MdlId;     // <0>
	int FeatureID; // <18> //��װ�����е�������ʶ
	ProType ModelitemType; // <3>       //
	ProName FeatureTypename;  //<Ԫ��>  //��������

	std::vector<creoFeature> features;
	std::vector<creoPart> parts;

public:
	creoAssembly();
	~creoAssembly();
};

