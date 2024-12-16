
#ifndef OSMR_UTIL_RESULT_PROXY_HPP
#define OSMR_UTIL_RESULT_PROXY_HPP

#include "util/typedefs.hpp"

namespace osrm::util::result_proxy
{

class ResultProxy
{
public:
    virtual int NoOp(int x) { return x; }

    virtual void Error(const std::string &code, const std::string &message) = 0;
    
    // [TODO] waypoint support
    //virtual void AddWaypoint();

    virtual void SetDistance(
        size_t source_idx, size_t destination_idx, float ds) = 0;
    virtual void SetDuration(
        size_t source_idx, size_t destination_idx, float dt) = 0;

    virtual void SetDistanceDuration(
        size_t source_idx, size_t destination_idx, float ds, float dt) = 0;

    virtual void DataVersion(const std::string &data_version) = 0;

    virtual ~ResultProxy() = default;
};

}  // namespace osrm::util::result_proxy


#endif  // OSMR_UTIL_RESULT_PROXY_HPP
