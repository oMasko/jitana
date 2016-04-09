/*
 * Copyright (c) 2016, Yutaka Tsutano
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef JITANA_APK_INFO_HPP
#define JITANA_APK_INFO_HPP

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace jitana {
    class apk_info {
    public:
        apk_info(const std::string& apk_dir)
        {
            boost::property_tree::ptree pt;
            read_xml(apk_dir + "/AndroidManifest.xml", pt);
            manifest_pt_ = pt.get_child("manifest");
        }

        std::string package_name() const
        {
            return manifest_pt_.get<std::string>("<xmlattr>.package");
        }

        const boost::property_tree::ptree& manifest_ptree() const
        {
            return manifest_pt_;
        }

    private:
        std::string apk_dir_;
        boost::property_tree::ptree manifest_pt_;
    };
}

#endif
