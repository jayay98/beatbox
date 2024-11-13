#include <iostream>
#include <sndfile.hh>
#include <Eigen/Dense>
#include <matplot/matplot.h>

int main () {
    // Initiation
    const char* file = "sample.wav";
    std::cout << "Reading file at: " << file << std::endl;

    // Reading file with sndfile
    SndfileHandle waveFile(file);
    std::cout << "Sampling rate: " << waveFile.samplerate() << std::endl;
    std::cout << "Number of frames in file: " << waveFile.frames() << std::endl;

    // Read signal into buffer
    int n_frames = waveFile.frames();
    double* buffer = new double[n_frames];
    waveFile.readf(buffer, n_frames);

    // Importing data from sndfile into Matrix
    Eigen::Map<Eigen::VectorXd> vec(buffer, n_frames);
    vec.normalize();

    // Visualize the signal
    std::vector<double> frame = matplot::linspace(0, n_frames);
    std::vector<double> data(vec.data(), vec.data() + n_frames);
    matplot::plot(frame, data);

    matplot::show();
    return 0;
}