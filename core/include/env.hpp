#pragma once

#include <string>
#include <optional>

namespace infosec_lab
{

struct Environment
{
    std::string id;
    std::string mr_id;
    std::string workspace_id;
    std::string owner;
};

class EnvironmentManager
{
public:
    std::string createFromMR(const std::string& mr_id, const std::string& owner);
    std::string invite(const std::string& env_id, const std::string& inviter, const std::string& invitee);
    bool acceptInvite(const std::string& invite_id, const std::string& user);
    std::optional<Environment> getEnv(const std::string& env_id);
};

}
