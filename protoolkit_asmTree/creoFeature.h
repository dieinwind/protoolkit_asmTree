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
	int FeatureID;              //������ʶ
	ProName featureName;        //������
	ProFeattype featureType;    //��������
	ProName featTypeName;       //����������
	ProLine featureSubType;     //����������
	int featureNum;            
 
public:
	creoFeature();
	creoFeature(ProFeature p_feature);
	~creoFeature();

	void printFeatureID();              //������ʶ
	void printfeatureName();        //������
	void printfeatureType();    //��������
	void printfeatTypeName();       //����������
	void printfeatureSubType();     //����������
	void printfeatureNum();
};

