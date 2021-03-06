H38329
s 00007/00004/00478
d D 1.19 04/08/05 12:16:53 staelin 20 19
c src/lat_ops.c
c - make the integer_div and int64_div operations more interesting and
c   less easily optimized (e.g., no division by one or two)
cC
cHhpliclu1.hpli.hpl.hp.com
cK60735
e
s 00033/00025/00449
d D 1.18 04/05/11 10:55:34 staelin 19 18
c - Fixup problems with int and int64 tests which allowed hardware and
c   software optimizations to skew the results.
cC
cK60894
e
s 00171/00141/00303
d D 1.17 04/05/09 13:11:23 staelin 18 17
c - Fixup float and double mul and div benchmarks to avoid multiplication
c   and division by 1.0, which can be hardware optimized
c - Manually unroll float and double bogomflops loops as many real codes
c   of this sort are also partially unrolled
cC
cHhpliclu2.hpli.hpl.hp.com
cK34254
cZ+03:00
e
s 00001/00001/00443
d D 1.16 03/12/11 09:07:45 staelin 17 16
c - Bugfix from James Yang; constants were silenty promoted to double
c   in loop measuring float performance, so measured double performanc
c   not float performance.
cC
cK54773
e
s 00009/00003/00435
d D 1.15 03/03/09 11:04:11 staelin 16 15
c - change benchmp() interface so we can have per-sample initialization
c   and cleanup.
cC
cHhpli69.hpli.hpl.hp.com
cK54569
cZ+02:00
e
s 00008/00006/00430
d D 1.14 02/01/07 01:30:01 staelin 15 14
c fix bug in integer bitwise operation expressions, which
c were optimizable by smart compilers.  Oops.
cC
cHdisks.bitmover.com
cK42428
cZ+00:00
e
s 00061/00103/00375
d D 1.13 01/11/15 14:22:59 staelin 14 13
c Change statements used in various lat_ops operation kernels to
c remove extraneous operations.  Fixed do_integer_bitwise to remove
c a shift operation; it now just does XORs.  Changed do_integer_mul
c so that it only does a bit operation (XOR) every ten multiplications,
c which should reduce the scope for measurement error.  Fixed 
c do_integer_div so it only does division operations.  Did similar fixes
c and changes for int64 operations.
cC
cK36945
cZ+02:00
e
s 00045/00062/00433
d D 1.12 01/05/14 11:35:15 staelin 13 12
c Add typedef for int64
c Switch lat_ops and par_mem from using benchmp() to BENCH() for performance reasons
c Change expression used in lat_ops and par_mem for measuring int and int64 add performance
c   to one that only uses '+' operations
cC
cK13407
cZ+03:00
e
s 00009/00004/00486
d D 1.11 01/04/02 14:50:33 staelin 12 11
c Add parallelism to lat_ops for three sub-benchmarks: integer bit, bogomflops, and double bogomflops
cC
cHhpli69.hpli.hpl.hp.com
cK14962
cZ+02:00
e
s 00002/00002/00488
d D 1.10 00/09/26 16:23:32 staelin 11 10
c - Fix buglet in lat_ops; miscounted number of operations executed for both float and
c   double bogomips computations
cC
cK03409
e
s 00019/00034/00471
d D 1.9 00/09/26 16:01:55 staelin 10 9
c - Fix bugs in lat_ops and par_ops in float_add, float_mul, double_add, and double_mul
c   which were causing arithmetic overflows which caused the benchmarks to crash
cC
cK03411
e
s 00041/00021/00464
d D 1.8 00/08/16 13:11:45 staelin 9 8
c - Add command line arguments for warmup and repetitions to lat_ops
cC
cK22069
e
s 00001/00001/00484
d D 1.7 00/08/10 16:13:04 staelin 8 7
c - Fix code that reports "uint64 add" latencies so results are properly identified.  From Chris Ruemmler
cC
cK36044
e
s 00004/00004/00481
d D 1.6 00/07/30 15:34:05 staelin 7 6
c - Add yet another workaround for GCC bugs
cC
cK36240
e
s 00044/00020/00441
d D 1.5 00/07/30 11:46:10 staelin 6 5
c - Change type of "iterations" from uint64 to iter_t, which is a u_long
cC
cK36918
e
s 00008/00008/00453
d D 1.4 00/07/27 14:36:59 staelin 5 4
c - Change expression used in do_integer_bit and do_uint64_bit benchmarks so GCC doesn't
c   optimize-away the loops
c - Simplify expression used in do_uint64_add so we only have add operations
c - Reformat bogomflops expressions so they are slightly more readable
cC
cK54762
e
s 00056/00007/00405
d D 1.3 00/07/26 18:09:55 staelin 4 3
c - Added workaround for GCC infinite loop bug
c - Changed bogomips to bogomflops
cC
cK57579
e
s 00166/00019/00246
d D 1.2 00/07/25 13:48:36 staelin 3 2
c - add new benchmarks for uint64 arithmetic (bit, add, mul, div, mod)
c - add new benchmark for integer add
c - fix bug in floating point and double benchmarks which allowed processor to overlap
c   some operations resulting in non-integer clock-tick operation speeds
c - change bogomips equations to match Richard G. Brown's latest equations from cpu-rate
c   0.0.3pre
cC
cK07223
e
s 00265/00000/00000
d D 1.1 00/07/24 09:54:59 staelin 2 1
cF1
cK22848
cO-rwxrwxr--
e
s 00000/00000/00000
d D 1.0 00/07/24 09:54:59 staelin 1 0
c BitKeeper file /tmp_mnt/usr/WebPaper/users/staelin/src/LMbench/src/lat_ops.c
cBlm@lm.bitmover.com|ChangeSet|20000131225335|47351|--LMBENCH--
cHhpli8.hpli.hpl.hp.com
cK53784
cPsrc/lat_ops.c
cR3e526da011aa72da
cV4
cX0xa1
cZ+03:00
e
u
U
f e 4
f x 0xa1
t
T
x^�]ms��}$�UnZ�zI�V(f���F[�4I�!�5	��I�@�j�����po �d{�$I v��v�go��+�m�t��C~z���19"��j<_��[MI.׋�D� ��0Z% ��{A�g��<Z���l��ָM����Q����<���&��E�"�jB^�q|O^����ܻD{W�f��f���y�HN��2�W)I#�l�#~��e���|>|� wO�QL�@(�$҄I���N��O��A�����-���*J��X�zK�m@�`��2^��I+8��e4�,6Tf���������	8�q����MLpb0�� ^D��jFdC�$"��C$si�0��
'�]8�����h�E3 ��q�Ƴ8*�C�:d�	'�����h�.�0_ٝ�f�O&4���,Z�D�p�r�s6q����hs��X�+p�<�a�03:\|�� �[��>�ށ��;�Y�d< �,"�6�0�Y@�;���&��' ����h� �f���p��8q���כL�hI/'�I,��0����]��^x,�I2�b�Ϣ�`�J"S�6a@f��	�GZQ���(I�[���ۆ�ì�`(k��LZ�(�_��x΍�2`k3�cI�p-�D�<�<�'	bE@�H6��O��٬�h� �.�h��}@m�OLi�\FJHR����q4P��)��"��*֏y1!���x�ǍN8!#��ǫ����6�O��x��d�R�x��l&i���&Iq�?7������~5���}=�#�f���6Ӭ�=�S ��ꟗ-����r���o/��˒������|�b(�4�8N����ͻ(��q)knB�n�/���hp��%���g�6�M��:����{DZʅN��@D�`�c,$�O��;�=�N	���,��x�Wޣq&��@i�A��x�L��h��m0/.R��*�z�i`�h�p�tHBrA2CCrp�1���?�?�D���{g���������"Ǭ}��h���b4Z.�(�x�f�(!)� ^��l�z�zv�9���d 	���i߆�0	Z81藸��U�r�T{�`��7��s�O�`FL��U#]$����v�l@e��N������"�p<��2̀��4D9�ߌ�a<�o<��?C�,#OH4 W��=��g%�d��q���?io�Z�gH�_@�i�&R�'oFR�(8!�������d���ـU	�Њe�]���2X˷Dj~t��^�.Q�I��k�X�$q��i��*�B���RS ��2{��z��2p{9�1-,"O��
V^rs����� �O���&�N��+�o��5���7W'ϱgY�нnf�xФ�t�b�7�$X@��>U���c�|���2��ڥ'��S%I��`t;�=��=�IA�*��I&�����r4"��`Ǖ��Eq�?��.I5�$l�$j~<r�8��UT�e�{m�
�jg�b���0��B}] ��	���$��tw'�F�'J\E#��@���
X�F���C�=�������=��2@�T����$�þ�h������G���<ft�랖�#�
��J�po �M�CB(}..����qzR��\69]�YRq^	9!���²�USZL�"+R��F�6(����#�}�A"�}԰[U�,�UF)ì�Π�I?f����gIU��V6[�\R��6�!o���۳�pAd�r04o�����Z�W.����g�k7��BvX�� !�M�Ս�ݍ�1�;�Ur��b����u�գȹ\;?gW���}hZ�]��籐���#l��)'�����=lg�	j�F�m���[��s����6��f����t��o֫���٬u4?�*PU�v�p�u_�-�e[l�ti4l��z��g�no�ѽ#�i�����g�m�)��Մ�4ĺ�2��׶z�7�{)ze�&Ƅ�>�]��>ʽ[�y�YQ�U�����~�Znj�I�ˍ���������3�Sn-8���C���6�:��$���~�$S,F�\gd�V"�-v�+��{q����jj��y�z���q��g��V�̽r1��S��^��������^�.�de F�=���G{����>��v.���$g�ռa�S����I�:�������A+��lί�\	�L��..�����f�#޻b��B�,�=VSs���`zk4����q�)b���0|A�e�dg�,>u��g'��I�z(��a������j��c�ʳ�OF����R��S�����
�V�U�����ǻL�b	k��|��E��䪔A��QY5G9�],:H�x&�
!n�Ή)pB=3�,�57X���!��Mt)�9A�Y�>;>��~�����=������q�ۯg�/AG�u�e�Cf�Q��p^|Q�cfʉ�9mV��(K\ֹ�����3\]��g�s�߉u5�C��o�u�q��w����¦�Q�'"-:�O��'���NLF^}�F�PѶ��>^�(L����ǘ�)���G`n�~W()~�����z��ƐKS
j҅�a�����iy��Ə����1n��R�C�?Yx�u@PƐ��p��lC������Q��J��h�Ng<{���~�()����w�J����O������]�5����H�/���'��I7\��mEU��/h�B]萒����R�����a�O�˛��H��dl�aJ��}>�p9�e��^���1��D�x�����a��e�)馬c�)�"���-
y1@x�DN�� �cm�֤H�<LIVś��d�:�[�5c�8Źb�3�[^�T��R&Ӓ>J���u�
���N�z��6��W�,�+�t�+��'��3I�%w�|�m�g��"?�nVuh�h�SA3��v]^qUK����"�'���ɤq���YT�7;���Z:K��}��<�M<jw������I�ϟ���SsM��$]�x�����ͩ�:����{r�Pȯw�����x�>����@�S�=M�Q��]U����1�w�|O��i�x��=!�W���<�|_ȟ��g�<������M�Q~ 䟪�O5y<F��B��*�L��c�&��U�sM�Q�����v�@񀦺�����]J�lb��i��(�{վ�e���*jh�B�i�@��T�N��v��4_l���v���i�|�0C�{��M�>��	�W�Jp���k��q�	~�t�;���Hõ��͊�CI���9�@�C��&*\���o�R��'$��>�Ŵ0Wģw~�ܬ)J�]vz�ǰ!	���B���~)>���?�.��l.�3��.ҟtP�H&2�F���&�gX0�8��\0����ptM.$���~S�B��&��kr!�ǲMt[TB���5F�p�X^y��=�$��Ɋ_É#�K��g������/�A�m��j�^:��wq�o9�J����x�'M�!�5�6;8�nV�[d#΂4Z�-�wH�������v��aD.�����]�J��V�F#y��9~Y��pD������s$L�C?��X�c�AWn���1�k&��H�;�U_3U	ۆ�=��#\
K���l��H�OrL��"�C����5�5��z�`a>$R�T�dYF�Z�E�\F��8BX�����_�Z�~��/W&��TF}WW!ڮ�`]kO���v,+��� ���l�Y�pi�̝��c]fK��m��fw�Q��A[R/W:)�r%6����k/���W��|h�gW�9X�`Uȥ3����#��1���,�e5ӟLj��2�*QE�����<�Y����=�"�v� aAQs��9��	:��~��^�)�ڞ���dy����`�!�/e��m4���F�j=�tUB�B�s����3��J,7�$�a�:�����駓f��80��0N9ɕn=�3���;»��n��|�r�[��^q��u��EI/�$�{@0�ʣ�f0Z��dK�9&;�Q���k�J�N�P��e����a�:�����oɷO'����;K�+���v��P)������2e+Ӓ�@~k��~��*X��܍qfΧҴ.�ebE[���hnd
U,�L���⓰6[�u��V�\�u��H�h��S��,E����ن�JP���L�Kx�L/�:�:���W����nh�w��}����l�T��`b�ꎫLI��m�ۮ�`�z�P;��	�jI����"�?���+嘱�مc����Te�o��$��|��%I��m���>�#�?����6�/�[j�l���ol�vA�a�<�.��}o����<���,�V��Y�ւi��ŝ@b�v�a�:U �}C�����ĲI� I��{�-r�j,^%w-��Fs��
lU��a��j�	���b����4"��S��tP>�Z�-�r Wi�/OGU���.&��BG2�����Q �Ĉ6
�ݢ%�ǵ/�y��YyŲ�F[�;[��saG���ӑf<����ծY�U��,��\�8V��2霌n�0Z��a�rG��	�ƭ
�ub��Ά7K��7�f,*��
Qgѯ;`1�@ǟ�5VحPWd�:�6������sY��C���R %T0��2�v�b]���
V�"-I�X]�x�Uf��vB�#�V<~f]�bÖ0�ji�,*j���b�ڃY�GV��S�ucW Q����V#��1��f��=��vz�ʧ%Ӄ�1�<��m��9�&�5Ι�v�RRXTT����b���<T�r	<�[�4�e�C��-$�D�(~P�czC���{ֱ��L���s[x�z�j��#N����zLwFI�4���j@g�^W۫��A?3��1N���G��,����
t��:��P��u:]l�y+I�1)���8�c�K��B�)/M@�W�@*g�P���ST8��Ֆ�S����`M�h�$�bćī��"� �Eu��Ѻ�`oзp�w.	��l�|�c�