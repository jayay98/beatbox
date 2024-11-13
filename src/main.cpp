#include <iostream>
#include <sndfile.hh>
#include <Eigen/Dense>
#include <sciplot/sciplot.hpp>

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
    sciplot::Plot2D plot;
        // Set the x and y labels
    plot.xlabel("x");
    plot.ylabel("y");

    // Set the x and y ranges
    plot.xrange(0.0, n_frames);
    plot.yrange(0.0, 1.0);
    std::cout << vec.norm() << std::endl;
    plot.drawCurve(sciplot::range(0, n_frames), (sciplot::Vec) *(vec.data()));

    // Create figure to hold plot
    sciplot::Figure fig = {{plot}};
    // Create canvas to hold figure
    sciplot::Canvas canvas = {{fig}};

    // Show the plot in a pop-up window
    canvas.show();
    return 0;
}