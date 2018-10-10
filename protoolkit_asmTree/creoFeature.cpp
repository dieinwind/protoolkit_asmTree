#include "creoFeature.h"



creoFeature::creoFeature()
{
}

creoFeature::creoFeature(ProFeature p_feature)
{
	Feature = p_feature;
	FeatureID = Feature.id;                         //特征标识
	ProModelitemNameGet(&Feature, featureName);     //特征名
	ProFeatureTypeGet(&Feature, &featureType);      //特征类型
	ProFeatureTypenameGet(&Feature, featTypeName);  //特征类型名
	ProFeatureSubtypeGet(&Feature, featureSubType); //特征子类型
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
