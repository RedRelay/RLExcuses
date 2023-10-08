#include "pch.h"
#include "RLExcuses.h"


void RLExcuses::RenderSettings() {
    ImGui::TextUnformatted("RLExcuse plugin settings");
    ImGui::TextUnformatted("This plugin will automatically post to chat the real reason for your loss, in the unlikely event that you're defeated. Probably by lag.");

    CVarWrapper isEnabledCvar = cvarManager->getCvar("RLExcuses.isEnabled");
    if (!isEnabledCvar) { return; }
    bool isEnabled = isEnabledCvar.getBoolValue();
    if (ImGui::Checkbox("Enable", &isEnabled)) {
        isEnabledCvar.setValue(isEnabled);
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip(isEnabledCvar.getDescription().c_str());
    }

    CVarWrapper isOnGoalEnabledCvar = cvarManager->getCvar("RLExcuses.isOnGoalEnabled");
    if (!isOnGoalEnabledCvar) { return; }
    bool isOnGoalEnabled = isOnGoalEnabledCvar.getBoolValue();
    if (ImGui::Checkbox("Enable on goal", &isOnGoalEnabled)) {
        isOnGoalEnabledCvar.setValue(isOnGoalEnabled);
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip(isOnGoalEnabledCvar.getDescription().c_str());
    }

    CVarWrapper isOnOwnGoalEnabledCvar = cvarManager->getCvar("RLExcuses.isOnOwnGoalEnabled");
    if (!isOnOwnGoalEnabledCvar) { return; }
    bool isOnOwnGoalEnabled = isOnOwnGoalEnabledCvar.getBoolValue();
    if (ImGui::Checkbox("Enable on own goal", &isOnOwnGoalEnabled)) {
        isOnOwnGoalEnabledCvar.setValue(isOnOwnGoalEnabled);
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip(isOnOwnGoalEnabledCvar.getDescription().c_str());
    }

    CVarWrapper isOnLostEnabledCvar = cvarManager->getCvar("RLExcuses.isOnLostEnabled");
    if (!isOnLostEnabledCvar) { return; }
    bool isOnLostEnabled = isOnLostEnabledCvar.getBoolValue();
    if (ImGui::Checkbox("Enable on lost", &isOnLostEnabled)) {
        isOnLostEnabledCvar.setValue(isOnLostEnabled);
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip(isOnLostEnabledCvar.getDescription().c_str());
    }

    CVarWrapper isExplainForAssholeEnabledCvar = cvarManager->getCvar("RLExcuses.isExplainForAssholeEnabled");
    if (!isExplainForAssholeEnabledCvar) { return; }
    bool isExplainForAssholeEnabled = isExplainForAssholeEnabledCvar.getBoolValue();
    if (ImGui::Checkbox("Explain what's going on when match ends", &isExplainForAssholeEnabled)) {
        isExplainForAssholeEnabledCvar.setValue(isExplainForAssholeEnabled);
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip(isExplainForAssholeEnabledCvar.getDescription().c_str());
    }

    CVarWrapper excusesFilePathCvar = cvarManager->getCvar("RLExcuses.excusesFilePath");
    if (!excusesFilePathCvar) { return; }
    char excusesFilePathBuffer[256];
    strcpy(excusesFilePathBuffer, excusesFilePathCvar.getStringValue().c_str());
    if (ImGui::InputText("Excuses file path", excusesFilePathBuffer, IM_ARRAYSIZE(excusesFilePathBuffer))) {
        excusesFilePathCvar.setValue(excusesFilePathBuffer);
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip(excusesFilePathCvar.getDescription().c_str());
    }
    
}

