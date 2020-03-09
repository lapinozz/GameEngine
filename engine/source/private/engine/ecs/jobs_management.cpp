#include <engine/ecs/jobs.hpp>
#include <engine/ecs/jobs_management.hpp>

#include <core/stl/vector.hpp>

namespace anton_engine {
    static anton_stl::Vector<Job*> jobs;

    i64 schedule_job(Job* job) {
        jobs.push_back(job);
		// TODO: Generate id
        return 0;
    }

    void execute_jobs() {
        for (Job* job: jobs) {
            job->execute();
        }

        jobs.clear();
    }
} // namespace anton_engine