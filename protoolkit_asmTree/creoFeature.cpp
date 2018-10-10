#include "creoFeature.h"



creoFeature::creoFeature()
{
}

creoFeature::creoFeature(ProFeature p_feature)
{
	Feature = p_feature;
	FeatureID = Feature.id;                         //������ʶ
	ProModelitemNameGet(&Feature, featureName);     //������
	ProFeatureTypeGet(&Feature, &featureType);      //��������
	ProFeatureTypenameGet(&Feature, featTypeName);  //����������
	ProFeatureSubtypeGet(&Feature, featureSubType); //����������
	ProFeatureNumberGet(&Feature, &featureNum);
}


creoFeature::~creoFeature()
{

}

void creoFeature::printFeatureID()
{
	std::cout << "FeatureID :<";
	printf("%d", FeatureID);
	std::cout << ">" << std::endl;
}

void creoFeature::printfeatureName()
{
	std::cout << "featureName :<";
	printf("%ls", featureName);
	std::cout << ">" << std::endl;
}

void creoFeature::printfeatureType()
{
	std::cout << "featureType :<"; 
	printf("%d", featureType);
	std::cout << ">" << std::endl;
}

void creoFeature::printfeatTypeName()
{
	std::cout << "featTypeName :<";
	printf("%ls", featTypeName);
	std::cout << ">" <<std::endl;
}

void creoFeature::printfeatureSubType()
{
	std::cout << "featureSubType :<";
	printf("%ls", featureSubType);
	std::cout << ">" << std::endl;
}

void creoFeature::printfeatureNum()
{
	std::cout << "featureNum :<";
	printf("%d", featureNum);
	std::cout << ">" << std::endl;
}
