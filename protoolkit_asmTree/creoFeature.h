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

class creoFeature
{
private:
	ProFeature Feature;
	ProMdl owner;
	int FeatureID;              //特征标识
	ProName featureName;        //特征名
	ProFeattype featureType;    //特征类型
	ProName featTypeName;       //特征类型名
	ProLine featureSubType;     //特征子类型
	int featureNum;            
 
public:
	creoFeature();
	creoFeature(ProFeature p_feature);
	~creoFeature();

	void printFeatureID();              //特征标识
	void printfeatureName();        //特征名
	void printfeatureType();    //特征类型
	void printfeatTypeName();       //特征类型名
	void printfeatureSubType();     //特征子类型
	void printfeatureNum();
};

