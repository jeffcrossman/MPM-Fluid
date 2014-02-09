/**
 * ofxMPMFluid.cpp
 * The MIT License (MIT)
 * Copyright (c) 2010 respective contributors
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 *  
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 *****************************************
 * ofxMPMFluid
 * Modifications by Jeff Crossman
 *   - Overloaded setup() for explicit placement of points
 *   - Added ability to set point color
 *   - Replaced vertex array draw method with point draw method
 *   - Replaced grid size defines with class variables and mutator
 *   - Updated syntax in ofxAutoControlPanel
 * http://www.jeffcrossman.com
 *
 * MPM FLuid Simulation Demo
 * OpenFrameworks version by Golan Levin
 * http://www.flong.com
 *
 * ofxAddon created by James George (@obviousjm)
 * http://www.jamesgeorge.org
 *
 * Original Java version:
 * http://grantkot.com/MPM/Liquid.html
 *
 * Flash version:
 * Copyright iunpin ( http://wonderfl.net/user/iunpin )
 * MIT License ( http://www.opensource.org/licenses/mit-license.php )
 * Downloaded from: http://wonderfl.net/c/6eu4
 *
 * Javascript version:
 * Copyright Stephen Sinclair (radarsat1) ( http://www.music.mcgill.ca/~sinclair )
 * MIT License ( http://www.opensource.org/licenses/mit-license.php )
 * Downloaded from: http://www.music.mcgill.ca/~sinclair/blog 
 */

#include "ofxMPMParticle.h"

ofxMPMParticle::ofxMPMParticle ( float inx, float iny, float inu, float inv) {
	x   = inx;
	y   = iny;
	u   = inu;
	v   = inv;
	pu  = 0;
	pv  = 0;
	cx  = 0; 
	cy  = 0;
    glc_r = 1.0;
    glc_g = 1.0;
    glc_b = 1.0;
    glc_a = 1.0;

	//px = new float[3];
	//py = new float[3];
	//gx = new float[3];
	//gy = new float[3];
}

ofxMPMParticle::ofxMPMParticle ( float inx, float iny, float inu, float inv,float inglc_r, float inglc_g, float inglc_b, float inglc_a) {
	x   = inx;
	y   = iny;
	u   = inu;
	v   = inv;
	pu  = 0;
	pv  = 0;
	cx  = 0;
	cy  = 0;
    
    // Sanitize input
    if (inglc_r > 1) {
        inglc_r = 1;
    }
    else if (inglc_r < 0){
        inglc_r = 0;
    }
    
    if (inglc_g > 1) {
        inglc_g = 1;
    }
    else if (inglc_g < 0){
        inglc_g = 0;
    }
    
    if (inglc_b > 1) {
        inglc_b = 1;
    }
    else if (inglc_b < 0){
        inglc_b = 0;
    }
    
    if (inglc_a > 1) {
        inglc_a = 1;
    }
    else if (inglc_a < 0){
        inglc_a = 0;
    }
    
    glc_r = inglc_r;
    glc_g = inglc_g;
    glc_b = inglc_b;
    glc_a = inglc_a;
    
	//px = new float[3];
	//py = new float[3];
	//gx = new float[3];
	//gy = new float[3];
}