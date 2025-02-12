
#ifndef OSMR_UTIL_RESULT_PROXY_HPP
#define OSMR_UTIL_RESULT_PROXY_HPP

#include <string>
#include <vector>

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

struct ResultProxyPtr
{
    ResultProxy *ptr = 0;
    ResultProxyPtr(ResultProxy *p): ptr(p) {}
    ResultProxyPtr() = default;
    ResultProxyPtr(const ResultProxyPtr&) = default;
    ResultProxyPtr(ResultProxyPtr&&) = default;
    ResultProxyPtr& operator=(const ResultProxyPtr&) = default;    
};

class ResultProxyTable
{
public:
    virtual int NoOp(int x) { return x; }

    // linear index
    static std::size_t lindex(std::size_t source_idx, std::size_t destination_idx, std::size_t number_of_columns)
    {
        return source_idx * number_of_columns + destination_idx;
    }

    virtual void Error(const std::string &code, const std::string &message) = 0;
    virtual void DataVersion(const std::string &data_version) = 0;
    virtual void Table(
        const std::pair<std::vector<EdgeDuration>, std::vector<EdgeDistance>> &tables,
        std::size_t number_of_rows,
        std::size_t number_of_columns
    ) = 0;
    virtual ~ResultProxyTable() = default;
};

struct ResultProxyTablePtr
{
    ResultProxyTable *ptr = 0;
    ResultProxyTablePtr(ResultProxyTable *p): ptr(p) {}
    ResultProxyTablePtr() = default;
    ResultProxyTablePtr(const ResultProxyTablePtr&) = default;
    ResultProxyTablePtr(ResultProxyTablePtr&&) = default;
    ResultProxyTablePtr& operator=(const ResultProxyTablePtr&) = default;
};


}  // namespace osrm::util::result_proxy


#endif  // OSMR_UTIL_RESULT_PROXY_HPP
