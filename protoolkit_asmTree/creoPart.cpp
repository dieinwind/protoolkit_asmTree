#include "creoPart.h"



creoPart::creoPart()
{
}

creoPart::creoPart(ProFeature * p_feat_handle)
{
	Feature = p_feat_handle;
	ProAsmcompMdlGet(Feature, &part);
	FeatureID = Feature->id;
	
	ProFeatureTypeGet(Feature, &FeatureType);
	ProFeatureTypenameGet(Feature, FeatureTypename);
	ProMdlMdlnameGet(part, Mdlname);
	ProMdlOriginGet(part, Origin);
	ProMdlDisplaynameGet(part, PRO_B_TRUE, Displayname);
}

creoPart::creoPart(ProMdl* p_mdl_handle)
{
	part = p_mdl_handle;
}


creoPart::~creoPart()
{
}

void creoPart::getFeatureID(int& id)
{
	id = FeatureID;
}

void creoPart::getDisplayname(ProMdlFileName display_name)
{
	
	ProMdlDisplaynameGet(part, PRO_B_TRUE, display_name);
}


void creoPart::getOrigin(ProPath origin)
{
	ProMdlOriginGet(part, Origin);
}

void creoPart::getFeatureType(ProFeattype featureType)
{
	
}

void creoPart::getFeatureTypename(ProName feattypename)
{
	
}

void creoPart::getMdlname(ProName name)
{
	
}

void creoPart::printDisplayname()
{
	printf("%ls", this->Displayname);
}

void creoPart::printOrigin()
{
	printf("%ls", Origin);
}

void creoPart::printMdlname()
{
	printf("%ls", Mdlname);
}

void creoPart::printFeatureID()
{
	printf("%d", FeatureID);
}

void creoPart::printFeatureTypename()
{
	printf("%ls", FeatureTypename);
}

