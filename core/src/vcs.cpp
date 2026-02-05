#include "vcs.hpp"
#include <fstream>
#include <filesystem>
#include <random>

namespace infosec_lab
{

std::string VCS::fork(const std::string& repo, const std::string& user)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1000, 9999);
    return "fork_" + std::to_string(dis(gen));
}

std::string VCS::createMR(const std::string& source, const std::string& target, const std::string& title, const std::string& author)
{
    std::filesystem::create_directories("data/vcs");
    std::string mr_id = "mr_" + std::to_string(std::random_device{}());
    std::ofstream f("data/vcs/" + mr_id + ".json");
    f << "{\"id\":\"" << mr_id << "\",\"source\":\"" << source << "\",\"target\":\"" << target << "\",\"author\":\"" << author << "\"}";
    return mr_id;
}

bool VCS::addReviewer(const std::string& mr_id, const std::string& reviewer)
{
    return std::filesystem::exists("data/vcs/" + mr_id + ".json");
}

bool VCS::submitReview(const std::string& mr_id, const std::string& reviewer, const std::string& decision)
{
    return std::filesystem::exists("data/vcs/" + mr_id + ".json");
}

bool VCS::approve(const std::string& mr_id, const std::string& approver)
{
    return std::filesystem::exists("data/vcs/" + mr_id + ".json");
}

bool VCS::checkRules(const std::string& mr_id)
{
    auto mr = getMR(mr_id);
    if (!mr.has_value()) return false;
    return mr->approvals.size() >= 1;
}

std::optional<MergeRequest> VCS::getMR(const std::string& mr_id)
{
    std::string path = "data/vcs/" + mr_id + ".json";
    if (!std::filesystem::exists(path)) return std::nullopt;
    MergeRequest mr;
    mr.id = mr_id;
    return mr;
}

}
