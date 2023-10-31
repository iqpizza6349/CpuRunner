#include <CpuUsage.h>

#include <string>
#include <boost/process.hpp>

namespace Cpusage {
    int usage() {
        boost::process::ipstream pipe_stream;
        boost::process::child process("wmic cpu get loadpercentage", boost::process::std_out > pipe_stream);

        std::string line;
        std::getline(pipe_stream, line);

        std::getline(pipe_stream, line);

        return std::stoi(line);
    }
}
