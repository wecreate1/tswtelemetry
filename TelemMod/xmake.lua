local projectName = "TelemMod"
add_requires("uwebsockets")

target(projectName)
    add_rules("ue4ss.mod")
    add_rules("mode.release")
    -- add_deps("TSWShared")
    add_headerfiles("Public/*.hpp")
    add_includedirs("Public")
    add_files("Private/*.cpp")
    add_syslinks("winhttp")
    add_packages("uwebsockets")
    add_packages("ImGuiTextEdit")