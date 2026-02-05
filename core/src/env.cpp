#include "env.hpp"
#include <fstream>
#include <filesystem>
#include <random>

namespace infosec_lab
{

std::string EnvironmentManager::createFromMR(const std::string& mr_id, const std::string& owner)
{
    std::filesystem::create_directories("data/env");
    std::string env_id = "env_" + std::to_string(std::random_device{}());
    std::string workspace_id = "ws_" + std::to_string(std::random_device{}());
    std::ofstream f("data/env/" + env_id + ".json");
    f << "{\"id\":\"" << env_id << "\",\"mr_id\":\"" << mr_id << "\",\"workspace_id\":\"" << workspace_id << "\",\"owner\":\"" << owner << "\"}";
    return env_id;
}

std::string EnvironmentManager::invite(const std::string& env_id, const std::string& inviter, const std::string& invitee)
{
    std::string invite_id = "inv_" + std::to_string(std::random_device{}());
    std::ofstream f("data/env/inv_" + invite_id + ".json");
    f << "{\"id\":\"" << invite_id << "\",\"env_id\":\"" << env_id << "\",\"inviter\":\"" << inviter << "\",\"invitee\":\"" << invitee << "\"}";
    return invite_id;
}

bool EnvironmentManager::acceptInvite(const std::string& invite_id, const std::string& user)
{
    return std::filesystem::exists("data/env/inv_" + invite_id + ".json");
}

std::optional<Environment> EnvironmentManager::getEnv(const std::string& env_id)
{
    std::string path = "data/env/" + env_id + ".json";
    if (!std::filesystem::exists(path)) return std::nullopt;
    Environment env;
    env.id = env_id;
    return env;
}

}
