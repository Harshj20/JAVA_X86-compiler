# Create the output directory if it doesn't exist
mkdir -p ../output
make
# Iterate over all the test case files in the tests directory
for test_file in ../tests/*.java; do
  # Extract the test case name without the extension
  test_name=$(basename "${test_file%.*}")
  # Create a separate directory for this test case in the output directory
  mkdir -p "../output/${test_name}"
  # Run the executable with the test case file as input and redirect the output to a file in the output directory
  ./milestone4 --input=../tests/"$test_file" --verbose --symtab > "../output/${test_name}/output.txt"
  # rm "../output/${test_name}/output.txt"
done

for test_file in ../output/*; do
  # Extract the test case name without the extension
  # Define the directory path
  dir_path="../output/${test_file}"
  # Loop through all files in the directory with .s extension
  for file_path in ${dir_path}/*.s; do
    # Extract the filename without the extension
    file_name=$(basename "${file_path}" .s)
    # Do something with the filename (e.g. print it to the console)
    gcc -c "$dir_path"/"$file_name".s -o code.o
    gcc code.o -o code
    echo "Output of $file_name"
    ./code
  done > "${dir_path}/output.txt"
done




