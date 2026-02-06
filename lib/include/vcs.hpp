#pragma once

#include <string>
#include <vector>
#include <optional>

namespace infosec_lab
{

struct MergeRequest
{
    std::string id;
    std::string source_branch;
    std::string target_branch;
    std::string author;
    std::string status;
    std::vector<std::string> reviewers;
    std::vector<std::string> approvals;
};

class VCS
{
public:
    std::string fork(const std::string& repo, const std::string& user);
    std::string createMR(const std::string& source, const std::string& target, const std::string& title, const std::string& author);
    bool addReviewer(const std::string& mr_id, const std::string& reviewer);
    bool submitReview(const std::string& mr_id, const std::string& reviewer, const std::string& decision);
    bool approve(const std::string& mr_id, const std::string& approver);
    bool checkRules(const std::string& mr_id);
    std::optional<MergeRequest> getMR(const std::string& mr_id);
};

}
