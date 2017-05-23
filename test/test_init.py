
import pytest
import pydash

def test_dash_init():
    
    pydash.init()
    assert(pydash.is_initialized())

    assert(pydash.myid() >= 0)
    assert(pydash.myid() < dash.size())

    pydash.finalize();
    assert(not pydash.is_initialized())

