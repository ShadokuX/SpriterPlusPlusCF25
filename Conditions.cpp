
#include "Common.h"

bool Extension::IsAnimationPlayingByName(TCHAR* name)
{
	if (IsScmlObjectValid())
	{
		wstring ws = wstring(name);
		string s(ws.begin(), ws.end());
		if (s == scmlObj->currentAnimationName())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool Extension::HasCurrentAnimationFinished()
{
	if (IsScmlObjectValid())
	{
		if (scmlObj->animationJustFinished())
		{
			#ifdef _DEBUG
				printf("%d: end of animation %s\n",currentSystemTime, scmlObj->currentAnimationName().c_str());
			#endif
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Extension::IsScmlObjectValid()
{
	return (scmlModel->fileCount()>0 && scmlObj != NULL);
}

bool Extension::IsTagActive(TCHAR* tagName)
{
	wstring wsVar = wstring(tagName);
	string sVar(wsVar.begin(), wsVar.end());
	return scmlObj->tagIsActive(sVar);
}

bool Extension::IsObjectTagActive(TCHAR* objectName, TCHAR* tagName)
{
	wstring wsObj = wstring(objectName);
	string sObj(wsObj.begin(), wsObj.end());
	wstring wsTag = wstring(tagName);
	string sTag(wsTag.begin(), wsTag.end());
	return scmlObj->tagIsActive(sObj, sTag);
}

bool Extension::OnSoundEvent(TCHAR* soundName)
{
	wstring wstr = wstring(soundName);
	string name(wstr.begin(), wstr.end());
	return (SoundEvent.erase(name));
}

bool Extension::OnTriggerEvent(TCHAR* triggerName)
{
	wstring wstr = wstring(triggerName);
	string name(wstr.begin(), wstr.end());
	return (TriggerEvent.erase(name));
}

bool Extension::IsAnimationFlipped()
{
	return flipX;
}

long Extension::CompareCurrentKeyFrameToValue(int val)
{
	return scmlObj->currentMainlineKeyIndex();
}


