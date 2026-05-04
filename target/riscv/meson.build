# FIXME extra_args should accept files()
gen = [
  decodetree.process('insn16.decode', extra_args: ['--static-decode=decode_insn16', '--insnwidth=16']),
  decodetree.process('insn32.decode', extra_args: '--static-decode=decode_insn32'),
  decodetree.process('xthead.decode', extra_args: '--static-decode=decode_xthead'),
  decodetree.process('XVentanaCondOps.decode', extra_args: '--static-decode=decode_XVentanaCodeOps'),
  decodetree.process('xmips.decode', extra_args: '--static-decode=decode_xmips'),
]

riscv_dup_ss = ss.source_set()
riscv_dup_system_ss = ss.source_set()
riscv_common_system_ss = ss.source_set()
riscv_common_ss = ss.source_set()
riscv_ss = ss.source_set()

riscv_ss.add(when: 'CONFIG_ARM_COMPATIBLE_SEMIHOSTING',
		     if_true: files('common-semi-target.c'))

riscv_ss.add(files(
  'cpu.c',
  'csr.c',
  'gdbstub.c',
  'vector_internals.c',
  'cpu_helper.c',
  'dummy.c',
))

riscv_dup_ss.add(files(
  'op_helper.c',
  'm128_helper.c',
  'vector_helper.c',
  'fpu_helper.c',
  'zce_helper.c',
  'crypto_helper.c',
  'vcrypto_helper.c',
  'bitmanip_helper.c',
  'translate.c',
))
riscv_dup_ss.add(gen)

riscv_common_system_ss.add(files(
  'debug.c',
  'translate-common.c',
))

riscv_system_ss = ss.source_set()
riscv_system_ss.add(files(
  'arch_dump.c',
  'pmp.c',
  'monitor.c',
  'machine.c',
  'mips_csr.c',
  'pmu.c',
  'th_csr.c',
  'time_helper.c',
  'riscv-qmp-cmds.c',
))

subdir('tcg')
subdir('kvm')

target_arch += {'riscv': riscv_ss}
target_system_arch += {'riscv': riscv_system_ss}
target_dup_arch += {'riscv' : riscv_dup_ss}
target_common_arch += {'riscv' : riscv_common_ss }
target_common_system_arch += {'riscv': riscv_common_system_ss}
#target_dup_system_arch += {'riscv': riscv_dup_system_ss}
