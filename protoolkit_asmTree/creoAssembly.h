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
	ProName Mdlname; // <PRT0001> //名字
	ProPath Origin; // <F:\Project\data_exchange\creo_workspace\protoolkit_asmTree\asm\prt0001.prt.1> //完整路径
	ProMdlExtension Extension; // <PRT>  //拓展名
	ProPath DirectoryPath; // <F:\Project\data_exchange\creo_workspace\protoolkit_asmTree\asm\>
	ProMdlType MdlType; // <2> PRO_PART
	ProMdlFileName Displayname; // <PRT0001.PRT> //名字
	int MdlId;     // <0>
	int FeatureID; // <18> //在装配体中的特征标识
	ProType ModelitemType; // <3>       //
	ProName FeatureTypename;  //<元件>  //特征类型

	std::vector<creoFeature> features;
	std::vector<creoPart> parts;

public:
	creoAssembly();
	~creoAssembly();
};

