# pcl_sample

## installation

- Install PCL on your PC from https://github.com/PointCloudLibrary/pcl/releases
- Add `PATH`
  - `C:\Program Files\YOUR_PCL\bin` (e.g. `C:\Program Files\PCL 1.11.0\bin`)
  - `C:\Program Files\YOUR_PCL\3rdParty\VTK\bin` (e.g. `C:\Program Files\PCL 1.11.0\3rdParty\VTK\bin`)
- Restart your PC
- Run following commands

```
$ git clone git@github.com:j20232/pcl_sample.git
$ mkdir build
$ cd build
$ cmake ..
$ Invoke-Item pcl_sample.sln
```

## References

- Official: https://github.com/PointCloudLibrary/pcl
- Python API: https://github.com/strawlab/python-pcl
