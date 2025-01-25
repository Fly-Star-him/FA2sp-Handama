#pragma once

#include <CMapValidator.h>

#include <unordered_set>

class CMapValidatorExt : public CMapValidator
{
public:
	void ValidateStructureOverlapping(BOOL& result);
	void ValidateMissingParams(BOOL& result);
	void ValidateLoopTrigger(BOOL& result);
	void ValidateLoopTrigger_loop(ppmfc::CString attachedTrigger);
	void ValidateRepeatingTaskforce(BOOL& result);
	void ValidateBaseNode(BOOL& result);
	void ValidateValueLength(BOOL& result);
	void ValidateEmptyTeamTrigger(BOOL& result);

	ppmfc::CString FetchLanguageString(const char* Key, const char* def);
	void InsertStringAsError(const char* String);
	void InsertString(const char* String, bool IsWarning);

	static std::unordered_set<std::string> StructureOverlappingIgnores;
	static std::vector<ppmfc::CString> AttachedTriggers;
	static std::vector<ppmfc::CString> LoopedTriggers;
};