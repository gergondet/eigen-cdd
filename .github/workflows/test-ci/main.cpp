#include <eigen-cdd/Polyhedron.h>

struct Rep {
    Rep()
        : AVrep(4, 3)
        , AHrep(4, 3)
        , bVrep(4)
        , bHrep(4)
    {
        AVrep << 1, 1, 2,
            1, -1, 2,
            -1, -1, 2,
            -1, 1, 2; // Friction cone inequality * 2
        AHrep << -2, 0, -1,
            0, -2, -1,
            2, 0, -1,
            0, 2, -1;
        bVrep << 0, 0, 0, 0;
        bHrep << 0, 0, 0, 0;
    }

    Eigen::MatrixXd AVrep, AHrep;
    Eigen::VectorXd bVrep, bHrep;
};

int main()
{
  bool ok = true;
  Rep rep;
  {
    Eigen::Polyhedron poly;
    poly.hrep(rep.AVrep, rep.bVrep);
    auto hrep = poly.hrep();
    ok = rep.AHrep.isApprox(hrep.first) && rep.bHrep.isApprox(hrep.second);
  }
  {
    Eigen::Polyhedron poly;
    poly.vrep(rep.AHrep, rep.bHrep);
    auto vrep = poly.vrep();
    ok = rep.AVrep.isApprox(vrep.first) && rep.bVrep.isApprox(vrep.second) && ok;
  }
  return ok ? 0 : 1;
}
