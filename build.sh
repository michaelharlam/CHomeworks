#!/bin/bash


function buildAndTest {
  local project_path
  project_path=$1
  local executable
  executable=$( basename "$project_path" )

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
      cmake .
      make
      cd ..

      if [ $? -ne 0 ]; then
        echo "Error: compilation failed in project $project_path"
        return 1
      fi

      echo "Running tests using ctest"
      cd "$project_path"
      ctest
      cd ..
      if [ $? -ne 0 ]; then
        echo "Tests failed in project: $project_path"
      else
        echo "Tests passed in project: $project_path"
      fi
    else
      echo "Compiling C source files in $project_path ..."

      clang $source_file -o "$project_path/$executable"

      if [ $? -ne 0 ]; then
        echo "Error: Compilation failed in project $project_path"
        return 1
      fi

      tests_file=$( find $project_path -name "tests")

      if [ -f "$tests_file" ]; then
        echo "Running tests using: $project_path"
        "$tests_file"

        test_result=$?

        if [ $test_result -ne 0 ]; then
          echo "Tests failed in project $project_path. Exit code: $test_result"
          return 1
        else
          echo "Tests passed in project: $project_path"
        fi
      else
        if [ -x "$project_path/$executable" ]; then
          echo "Executing project: $project_path/$executable"
          "$project_path/$executable"

          test_result=$?

          if [ $test_result -ne 0 ]; then
            echo "Tests failed in project $project_path. Exit code: $test_result"
            return 1
          else
            echo "Tests passed in project: $project_path"
          fi
        else
          echo "Warning! No executable found"
          return 0
        fi
      fi
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