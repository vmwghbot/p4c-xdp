/*
Copyright 2017 VMware, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "target.h"

namespace XDP {

void XdpTarget::emitIncludes(Util::SourceCodeBuilder* builder) const {
    builder->append(
        "#define KBUILD_MODNAME \"xdptest\"\n"
        "#include <linux/bpf.h>\n"
        "#include \"ebpf_xdp.h\"\n"
        "\n");
}

void XdpTarget::emitMain(Util::SourceCodeBuilder* builder,
                         cstring functionName,
                         cstring argName) const {
    builder->appendFormat("int %s(struct xdp_md* %s)", functionName, argName);
}

}  // namespace XDP
