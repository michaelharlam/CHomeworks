#!/bin/bash

set -e

function buildAndTest {
  local project_path
  project_path=$1
  local executable
  executable=$( basename "$project_path" )

  ls
  echo "========================================================"
  echo "Building and testing project: $project_path ..."
  echo "========================================================"

  if [ ! -d "$project_path" ]; then
    echo "Project directory not found: $project_path"
    return 1
  fi

  source_file=$( find $project_path -name "*.c" )

  if [ -z "$source_file" ]; then
    echo "Warning! No C files in directory $project_path"
    return 0
  else
    if find $project_path -name "CMakeLists.txt"; then
      echo "Using CMake to build project"
      cd "$project_path"
      ls
      cmake .
      make
      mv "$executable" "cmake-build-debug"

      if [ $? -ne 0 ]; then
        echo "Error: compilation failed in project $project_path"
        return 1
      fi

      "cmake-build-debug/$executable"

      run=$?

      if [ $run -ne 0 ]; then
        echo "Tests failed in project $project_path "
        cd ../..
        return 1
      else
        echo "Tests passed in project $project_path"
        cd ../..
        return 0
      fi
    else
      echo "Warning! There is no CMake file in C project $project_path"
      return 1
    fi
  fi
}


projects=$( find . -mindepth 2 -maxdepth 2 -type d -not -path "./.git" -not -path "./build" )

for project in $projects; do
  buildAndTest "$project"
done

echo "========================================================"
echo "Finished testing all projects"
echo "========================================================"