
import pytest
import dash

def test_dash_init()
    
    dash.init()
    assert(dash.is_initialized())

    assert(dash.myid() >= 0)
    assert(dash.myid() < dash.size())

    dash.finalize();
    assert(!dash.is_initialized())

