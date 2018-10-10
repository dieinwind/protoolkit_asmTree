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

using namespace std;



// ʵ��ģ���������ʺ���
ProError PartFeatVisitFunc(ProFeature* p_feature,
	ProError status,
	ProAppData app_data)
{
	// �ж��ǲ���Ԫ������
	ProError err;
	ProFeattype featType;
	ProFeatureTypeGet(p_feature, &featType);
	if (PRO_FEAT_COMPONENT != featType)
	{
		return PRO_TK_NO_ERROR;
	}
	vector<creoPart>* pFeatVec = (vector<creoPart>*)app_data;
	pFeatVec->push_back(creoPart(p_feature));

	return PRO_TK_NO_ERROR;
}

// ʵ��ģ���������ʺ���
ProError SolidFeatVisitFunc(ProFeature* p_feature,
	ProError status,
	ProAppData app_data)
{
	vector<creoFeature>* pFeatVec = (vector<creoFeature>*)app_data;
	pFeatVec->push_back(creoFeature(*p_feature));
	return PRO_TK_NO_ERROR;
}


int main()
{
	int expType = -1;
	ProError status;
	
	ProBoolean random_choice;
	ProProcessHandle proConnHdl;
	cout << "ProEngineerConnect start...."<<endl;
	status = ProEngineerConnect("", NULL, NULL, "", PRO_B_TRUE, 2, &random_choice, &proConnHdl);
	cout << "ProEngineerConnect end...." << endl;
	if (PRO_TK_NO_ERROR != status)
	{
		wcout << "��"<< status <<"�� ProEngineerConnectδ���ӣ�������һ��ProEngineer" << endl;
		cout << "ProEngineerStart start...." << endl;
		// -g:no_graphics -i:rpc_input
		status = ProEngineerConnectionStart("C:\\EDAIntegeration\\tceda\\parametric.bat -g:no_graphics -i:rpc_input", "", &proConnHdl);//����Creo����
		cout << "ProEngineerStart end...." << endl;
		if (PRO_TK_NO_ERROR != status)
		{
			wcout << "��" << status << "�� ProEngineerStartδ������Creo" << endl;
			return -1;
		}
	}

	//�������
	char *partPath = "F:\\Project\\data_exchange\\creo_workspace\\protoolkit_asmTree\\asm\\asm0001.asm.5";
	ProPath ProPartPath;
	ProMdl proMdHdl;
	ProPart proPart;
	ProSolid proSolid;
	ProNativestringToWstring(ProPartPath, PRO_PATH_SIZE, partPath, strlen(partPath));
	status = ProMdlLoad(ProPartPath, PRO_MDL_ASSEMBLY, PRO_B_FALSE, &proMdHdl);
	if (PRO_TK_NO_ERROR != status)
	{
		cout << "[" << status << "]can't load file:" << partPath << endl;
		return -1;
	}
	// ��������ģ���µ���������
	vector<creoFeature> vecFeat;
	status = ProSolidFeatVisit((ProSolid)proMdHdl, SolidFeatVisitFunc, NULL, &vecFeat);

	// ���������������Ϣ
	vector<creoFeature>::iterator iterFeat = vecFeat.begin();
	cout << "There are < " << vecFeat.size() << " > Features;" << endl;
	for (; iterFeat != vecFeat.end(); ++iterFeat)
	{

		cout << endl;
		(*iterFeat).printFeatureID();              //������ʶ
		(*iterFeat).printfeatureName();        //������
		(*iterFeat).printfeatureType();    //��������
		(*iterFeat).printfeatTypeName();       //����������
		(*iterFeat).printfeatureSubType();     //����������
		(*iterFeat).printfeatureNum();


		/*
		cout << endl;
		//������
		ProName featName;
		ProModelitemNameGet(&(*iterFeat), featName);
		cout << "featName :<";  printf("%ls", featName); cout << ">" << endl;

		ProFeattype featType;
		ProFeatureTypeGet(&(*iterFeat), &featType);
		cout << "featType :<";  cout << featType; cout << ">" << endl;

		// ����������
		ProLine subtype;
		ProFeatureSubtypeGet(&(*iterFeat), subtype);
		cout << "subtype :<";  printf("%ls", subtype); cout << ">" << endl;

		//����������
		ProName feattypename;
		ProFeatureTypenameGet(&(*iterFeat), feattypename);
		cout << "ProFeatureTypename :<";  printf("%ls", feattypename); cout << ">" << endl;

		int r_feat_num;
		ProFeatureNumberGet(&(*iterFeat), &r_feat_num);
		cout << "r_feat_num :<";  cout << r_feat_num; cout << ">" << endl;

		//������ʶ
		int FeatID = iterFeat->id;
		cout << "FeatID :<";  cout << FeatID; cout << ">" << endl;
		*/
	}

	//status = ProWindowCurrentClose();
	//cout << "��" << status << "��ProWindowCurrentClose" << endl;
	//status = ProMdlEraseAll(proMdHdl);
	//cout << "��" << status << "��ProMdlEraseAll" << endl;
	//status = ProEngineerEnd();
	//cout << "��" << status << "��ProEngineerEnd" << endl;
	status = ProEngineerDisconnect(&proConnHdl, 2);
	cout << "��" << status << "��ProEngineerDisconnect" << endl;
	cout << "Function End--------------------------------\r\n" << endl;
	return 0;

}